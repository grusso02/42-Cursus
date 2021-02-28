# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grusso <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 13:01:33 by grusso            #+#    #+#              #
#    Updated: 2021/02/28 18:47:48 by grusso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Sistema operativo
FROM debian:buster

#Installo e aggiorno
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get -y install wget

#Installo NGINX
RUN apt-get -y install nginx
RUN rm -rf /etc/nginx/sites-available/default
COPY /srcs/nginx-config /etc/nginx/sites-available/default

#Installo MariaDB
RUN apt-get -y install mariadb-server

#Installo PHP
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

#Installo phpMyAdmin
WORKDIR /var/www/html
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin

#Installo WP
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz

#Copio i config-fil php e wp
COPY /srcs/config.inc.php phpmyadmin/config.inc.php
COPY /srcs/wp-config.php wordpress/wp-config.php

#Cambia autorizzazioni
RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*

#Avvio Nginx
WORKDIR ../../../
COPY /srcs/init-container.sh ./
COPY /srcs/autoindex_off.sh ./
COPY /srcs/autoindex_on.sh ./
RUN chmod -R 777 autoindex*
CMD bash init-container.sh
