#!/usr/bin/env python

import argparse
import os
import os.path
import tarfile
import shutil
import logging
import pycurl
import six
from six import StringIO

def makedirs(apath):
    if not os.path.exists(apath):
        os.makedirs(apath)

def copy_recursively(from_dir, to_dir):
    """
    Copy files recursively.

    NOTICE: This function will overwrite files, that's great different from
    shutil.copytree().
    """

    real_root = os.path.realpath(from_dir)
    for root, dirs, files in os.walk(from_dir):
        for adir in dirs:
            from_path = os.path.realpath(os.path.join(root, adir))
            to_path = os.path.realpath(os.path.join(to_dir, "." + from_path[len(real_root):]))
            makedirs(to_path)

        for afile in files:
            from_path = os.path.realpath(os.path.join(root, afile))
            to_path = os.path.realpath(os.path.join(to_dir, "." + from_path[len(real_root):]))
            shutil.copy(from_path, to_path)

def download_file(url):
    with open(os.path.basename(url), "wb") as output_file:
        c = pycurl.Curl()
        c.setopt(pycurl.URL, url)
        c.setopt(pycurl.NOPROGRESS, 0) # Display progress ...
        c.setopt(pycurl.FOLLOWLOCATION, 1)
        c.setopt(pycurl.MAXREDIRS, 10)
        c.setopt(pycurl.TIMEOUT, 300)
        c.setopt(pycurl.CONNECTTIMEOUT, 60)
        c.setopt(pycurl.USERAGENT,
                 "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 1.1.4322)")
        c.setopt(pycurl.WRITEDATA, output_file)
        c.perform()

def main():
    logging.basicConfig(level=logging.NOTSET) # Enable logging

    logger = logging.getLogger(__name__)

    package_name = "uClibc++-0.2.4"
    file_name = "%s.tar.bz2" % package_name

    logger.info("Rebuild 'src' directory ...")

    shutil.rmtree("./src", ignore_errors=True)
    makedirs("./src")

    makedirs("__build__")
    os.chdir("__build__")

    if os.path.exists(file_name):
        logger.info("%s existed." % file_name)
    else:
        logger.info("Downloading %s ..." % file_name)
        download_file("https://git.busybox.net/uClibc++/snapshot/%s" % file_name)

    logger.info("Unpack %s ..." % file_name)
    with tarfile.open(file_name, "r:bz2") as atarfile:
        atarfile.extractall()

    logger.info("Patching sources ...")

    copy_recursively("./%s/src" % package_name, "../src")
    copy_recursively("./%s/include" % package_name, "../src")
    copy_recursively("../patch_src", "../src")

    os.remove("../src/support.cpp")

    with open("../src/memory", "a") as afile:
        afile.write('\n#include "patches/memory"\n')

    with open("../src/stdexcept", "a") as afile:
        afile.write('\n#include "patches/exception"\n')

    logger.info("Done!")

if __name__ == "__main__":
    main()
