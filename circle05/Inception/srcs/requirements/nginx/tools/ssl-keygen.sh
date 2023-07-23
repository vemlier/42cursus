#!/bin/sh

mkdir -p /etc/nginx/ssl

if [ ! -e /etc/nginx/ssl/chukim.42.fr.crt ]; then
    openssl req -newkey rsa:2048 -nodes -keyout /etc/nginx/ssl/chukim.42.fr.key -x509 -days 365 -out /etc/nginx/ssl/chukim.42.fr.crt -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=chukim/CN=chukim.42.fr"
fi
