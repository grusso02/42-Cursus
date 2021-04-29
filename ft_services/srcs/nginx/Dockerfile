FROM    alpine:latest

RUN		apk update
RUN		apk upgrade
RUN		apk add nginx openssl
RUN		mkdir -p /run/nginx

COPY    setup.sh /
COPY    nginx.conf /etc/nginx/

# Setup pagina HTML
COPY    index.html /var/www/html/

# Telegraf
RUN     apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache
RUN     mkdir /etc/telegraf
COPY    telegraf.conf /etc/telegraf

EXPOSE	22 80 443

RUN		chmod 777 ./setup.sh
CMD		./setup.sh