#!/bin/bash
if [ $USER == "root" ]
then
    dnf install -y libtool-ltdl-devel
    git clone https://github.com/logictech31/collectd
    cd collectd
    git checkout collectd-5.2
    sh build.sh
    echo "COLLECTD_DIR=\"/root/collectd-5.12.0\"" | tee -a /root/.bashrc
    echo "export PATH=\"$PATH:$COLLECTD_DIR/bin\"" | tee -a /root/.bashrc

    echo "Opening collectd-github, collectd-exporter, lustre-wiki websites"
    firefox https://github.com/prometheus/collectd_exporter https://www.collectd.org/documentation/ https://wiki.lustre.org/Main_Page
else
    echo "Run this as root user."
fi