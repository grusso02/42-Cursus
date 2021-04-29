FROM	alpine

EXPOSE 21 30000 30020 30021

RUN		apk update && apk add vsftpd
RUN		apk add --no-cache openssl

RUN     mkdir admin/
COPY    vsftpd.conf /etc/vsftpd/

RUN     openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes  -out /etc/ssl/vsftpd.crt  -keyout /etc/ssl/vsftpd.key -subj "/C=IT"
RUN		adduser -D admin
RUN		echo "admin:admin" | chpasswd

# Telegraf
RUN     apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache
RUN     mkdir /etc/telegraf
COPY    telegraf.conf /etc/telegraf

COPY    start.sh ./start.sh
RUN		chmod 755 ./start.sh
CMD		sh start.sh