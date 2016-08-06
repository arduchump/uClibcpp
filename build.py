#!/usr/bin/env python

import argparse
import os
import os.path
import tarfile
import shutil

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

def main():
    package_name = "uClibc++-0.2.4"
    file_name = "%s.tar.bz2" % package_name

    shutil.rmtree("./src", ignore_errors=True)
    makedirs("./src")

    makedirs("__build__")
    os.chdir("__build__")

    if not os.path.exists(file_name):
        os.system("wget https://git.busybox.net/uClibc++/snapshot/%s" % file_name)

    with tarfile.open(file_name, "r:bz2") as atarfile:
        atarfile.extractall()

    copy_recursively("./%s/src" % package_name, "../src")
    copy_recursively("./%s/include" % package_name, "../src")
    copy_recursively("../patch_src", "../src")

    os.remove("../src/support.cpp")

    with open("../src/memory", "a") as afile:
        afile.write('\n#include "patches/memory"\n')

    with open("../src/stdexcept", "a") as afile:
        afile.write('\n#include "patches/exception"\n')

if __name__ == "__main__":
    main()
