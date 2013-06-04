#include "Python.h"

static PyMethodDef modtest_methods[] = {
    {NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
"ModTest");

PyMODINIT_FUNC
initmodtest(void)
{
    PyObject *m;

    PyObject* leaked_str = PyString_FromString("Leak me!");

    /* Create the module and add the functions */
    m = Py_InitModule3("modtest", modtest_methods, module_doc);
}
