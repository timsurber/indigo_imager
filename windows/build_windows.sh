#!/bin/bash

APP=ain_imager
VIEWER=ain_viewer
QT_VER=6.4.2


export PATH=/c/Qt/${QT_VER}/mingw_64/bin/:$PATH


./build_libs_win64.sh
# build imager
pushd .
[ ! -d "${APP}_64" ] && mkdir ${APP}_64
cd ${APP}_64
qmake6 ../../${APP}_src/${APP}.pro
mingw32-make -f Makefile.release

[ ! -d "${APP}" ] && mkdir ${APP}
cd ${APP}
cp ../release/${APP}.exe .
cp ../../../external/indigo_sdk/lib/libindigo_client.dll .
windeployqt ${APP}.exe
popd

# build viewer
pushd .
[ ! -d "${VIEWER}_64" ] && mkdir ${VIEWER}_64
cd ${VIEWER}_64
qmake6 ../../${VIEWER}_src/${VIEWER}.pro
mingw32-make -f Makefile.release
cp release/${VIEWER}.exe ../${APP}_64/${APP}
popd

APP_VERSION=`grep AIN_VERSION ../common_src/version.h | sed 's/"//g' |awk '{ print $3 }'`

# bundle qt and application in installer
iscc -DArch=64 -DMyAppVersion=$APP_VERSION ${APP}.iss
