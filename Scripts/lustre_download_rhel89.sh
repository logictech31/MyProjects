#!/bin/bash
if [ $USER == "root" ]
then
    echo "[lustre-client]
    name=Lustre Client Repository
    baseurl=https://downloads.whamcloud.com/public/lustre/latest-release/el8.9/client
    enabled=1
    gpgcheck=0

    [lustre-server]
    name=Lustre Server Repository
    baseurl=https://downloads.whamcloud.com/public/lustre/latest-release/el8.9/server
    enabled=1
    gpgcheck=0

    [e2fsprogs]
    name=e2fsprogs
    baseurl=https://downloads.whamcloud.com/public/e2fsprogs/latest/el8
    enabled=1
    gpgcheck=0" >> lustre.repo
    mv lustre.repo /etc/yum.repos.d/
    yum makecache
    yum install -y https://downloads.whamcloud.com/public/lustre/latest-release/el8.9/server/RPMS/x86_64/kernel-4.18.0-513.9.1.el8_lustre.x86_64.rpm
    yum install -y e2fsprogs lustre
    dnf install -y git flex libtool pkg-config autoconf automake bison lustre-tests
    reboot
else
    echo "Run this as root user."
fi