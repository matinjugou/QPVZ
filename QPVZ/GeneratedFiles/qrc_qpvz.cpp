/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.7.0
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // D:/??/????/??????/??/QPVZ/QPVZ/Resources/files/SettingsFiles.txt
  0x0,0x0,0x0,0xe4,
  0x31,
  0xd,0xa,0x33,0x30,0xd,0xa,0x33,0x20,0x35,0xd,0xa,0x31,0x20,0x34,0x38,0xd,
  0xa,0x31,0x20,0x36,0x31,0xd,0xa,0x31,0x20,0x37,0x37,0xd,0xa,0x31,0x20,0x38,
  0x35,0xd,0xa,0x31,0x20,0x39,0x35,0xd,0xa,0x31,0x20,0x31,0x30,0x30,0xd,0xa,
  0x31,0x20,0x31,0x31,0x35,0xd,0xa,0x32,0x20,0x31,0x31,0x38,0xd,0xa,0x31,0x20,
  0x31,0x31,0x38,0xd,0xa,0x31,0x20,0x31,0x32,0x36,0xd,0xa,0x31,0x20,0x31,0x32,
  0x36,0xd,0xa,0x31,0x20,0x31,0x32,0x36,0xd,0xa,0x31,0x20,0x31,0x34,0x30,0xd,
  0xa,0x31,0x20,0x31,0x34,0x30,0xd,0xa,0x31,0x20,0x31,0x34,0x30,0xd,0xa,0x31,
  0x20,0x31,0x35,0x30,0xd,0xa,0x31,0x20,0x31,0x35,0x30,0xd,0xa,0x31,0x20,0x31,
  0x35,0x30,0xd,0xa,0x31,0x20,0x31,0x35,0x30,0xd,0xa,0x31,0x20,0x31,0x37,0x30,
  0xd,0xa,0x31,0x20,0x31,0x37,0x30,0xd,0xa,0x31,0x20,0x31,0x37,0x30,0xd,0xa,
  0x31,0x20,0x31,0x37,0x30,0xd,0xa,0x31,0x20,0x31,0x37,0x30,0xd,0xa,0x31,0x20,
  0x31,0x37,0x30,0xd,0xa,0x31,0x20,0x31,0x37,0x30,0xd,0xa,0x31,0x20,0x31,0x37,
  0x30,0xd,0xa,0x31,0x20,0x31,0x37,0x30,0xd,0xa,0x31,0x20,0x31,0x37,0x30,0xd,
  0xa,0x33,0xd,0xa,0x31,0xd,0xa,0x32,0xd,0xa,0x33,0xd,0xa,0x31,0xd,0xa,
  0x31,0x30,0x30,
  
};

static const unsigned char qt_resource_name[] = {
  // QPVZ
  0x0,0x4,
  0x0,0x5,0x65,0xba,
  0x0,0x51,
  0x0,0x50,0x0,0x56,0x0,0x5a,
    // SettingsFile
  0x0,0xc,
  0xf,0xde,0xba,0x25,
  0x0,0x53,
  0x0,0x65,0x0,0x74,0x0,0x74,0x0,0x69,0x0,0x6e,0x0,0x67,0x0,0x73,0x0,0x46,0x0,0x69,0x0,0x6c,0x0,0x65,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/QPVZ
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
  // :/QPVZ/SettingsFile
  0x0,0x0,0x0,0xe,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_qpvz)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_qpvz)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qpvz)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qpvz)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_qpvz)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_qpvz)(); }
   } dummy;
}
