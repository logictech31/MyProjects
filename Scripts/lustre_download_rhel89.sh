#!/bin/bash
if [ $USER == "root" ]
then
echo "[lustre-client]
name=Lustre Client Repository
baseurl=https://downloads.whamcloud.com/public/lustre/lustre-2.15.4/el8.9/client
enabled=1
gpgcheck=0

[lustre-server]
name=Lustre Server Repository
baseurl=https://downloads.whamcloud.com/public/lustre/lustre-2.15.4/el8.9/server
enabled=1
gpgcheck=0

[e2fsprogs]
name=e2fsprogs
baseurl=https://downloads.whamcloud.com/public/e2fsprogs/latest/el8
enabled=1
gpgcheck=0" >> lustre.repo
mv lustre.repo /etc/yum.repos.d/
yum makecache
dnf install -y lustre
dnf install -y git flex libtool pkg-config autoconf automake bison lustre-tests
reboot
else
    echo "Run this as root user."
fi
