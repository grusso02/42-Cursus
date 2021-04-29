telegraf &
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/42roma.pem -keyout /etc/nginx/ssl/42roma.key -subj "/C=IT/ST=Roma/L=Roma/O=42Rome/OU=russo/CN=42Roma"

nginx -g 'daemon off;'