pls use  build/bin/dumpnet to dump model to xml
(just cmake .. and then make -j8)
if download ipp fail-  please reference 3rdparty\ippicv\downloader.cmake (file(DOWNLOAD "${OPENCV_ICV_URL}/${OPENCV_ICV_PACKAGE_NAME}" "${OPENCV_ICV_PACKAGE_ARCHIVE}")
and copy to OPENCV_ICV_PACKAGE_ARCHIVE
