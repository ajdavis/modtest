#include "Python.h"

static PyObject* leaky(PyObject* self, PyObject* args) {
    PyObject *leaked = PyString_FromString("leak!");
    Py_XINCREF(leaked);
    return leaked;
}

static PyObject* crashy(PyObject* self, PyObject* args) {
    PyObject *p = PyString_FromString("crash!");
    Py_INCREF(p);
    return p;
}

static PyObject* randerr(PyObject* self, PyObject* args) {
    PyObject *p = NULL;
    if ((float)rand()/(float)RAND_MAX > 0.5)
        p = PyString_FromString("foo");

    return p;
}

static int maybe_error() {
    if ((float)rand()/(float)RAND_MAX > 0.5) {
        PyErr_SetString(PyExc_Exception, "error");
        return 1;
    } else {
        return 0;
    }
}

static PyObject* caller(PyObject* self, PyObject* args) {
    if (maybe_error()) {
        /* I know the error has been set. */
        return NULL;
    } else {
        return PyString_FromString("foo");
    }
}

static PyObject* parse(PyObject* self, PyObject* args) {
    int i;
    const char* s;
    float f;
    if (!PyArg_ParseTuple(args, "is", &i, &s, &f)) {
        return NULL;
    }

    return PyString_FromFormat("got %d %s", i, s);
}


static PyMethodDef modtest_methods[] = {
    {"leaky",   leaky,   METH_VARARGS, ""},
    {"crashy",  crashy,  METH_VARARGS, ""},
    {"randerr", randerr, METH_VARARGS, ""},
    {"caller",  caller,  METH_VARARGS, ""},
    {"parse",   parse,   METH_VARARGS, ""},
    {NULL, NULL} /* sentinel */
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
