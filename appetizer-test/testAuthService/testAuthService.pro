QT += gui core widgets testlib sql
CONFIG += c++14 qt warn_on depend_includepath testcase
TARGET = testAuthService
TEMPLATE = app
APPETIZER_APP_PATH = ../../appetizer-core
INCLUDEPATH += $${APPETIZER_APP_PATH}
DEPENDPATH += $${APPETIZER_APP_PATH}
include(../../Appetizer.pri)
SOURCES +=  tst_authenticationservice.cpp 
