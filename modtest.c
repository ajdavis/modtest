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

    /* Create the module and add the functions */
    m = Py_InitModule3("modtest", modtest_methods, module_doc);
    if (m == NULL)
        return;

    PyErr_SetString(PyExc_ImportError, "foo bar");
}
