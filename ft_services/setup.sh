# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    setup.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grusso <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/16 18:39:45 by grusso            #+#    #+#              #
#    Updated: 2021/04/17 16:41:38 by grusso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

function metallinstall()
{
	printf "\e[39m START BUILDING \e[5;92mmetallb\e[0m\r"
	start=`date +%s`
	kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml >> last.log
	kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml >> last.log
	kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" >> last.log
	kubectl apply -f srcs/metallb/. >> last.log
	end=`date +%s`
	runtime=$((end-start))
	printf "\e[K\e[92m metallb DONE (in ${runtime}s)!\e[0m\n"
}
