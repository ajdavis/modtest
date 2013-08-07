#include "Python.h"

static PyObject* method(PyObject* self, PyObject* args) {
    PyObject *leaked = PyString_FromString("Leak!");
    Py_XINCREF(leaked);
    return leaked;
}

static PyMethodDef modtest_methods[] = {
    {"method", method, METH_VARARGS, ""},
    {NULL,              NULL} /* sentinel */
};

PyDoc_STRVAR(module_doc,
"ModTest");

PyMODINIT_FUNC
initmodtest(void)
{
    PyObject *m = Py_InitModule3(
        "modtest",
        modtest_methods,
        module_doc);
}
