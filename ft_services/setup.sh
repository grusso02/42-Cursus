killall kubectl

# Create images
docker build -t nginx_img ./srcs/nginx/
docker build -t testmysql:latest ./srcs/mysql
docker build -t php_img ./srcs/phpmyadmin/
docker build -t testwordpress ./srcs/wordpress
docker build -t ftps_img ./srcs/ftps/
docker build -t influxdb_alpine ./srcs/influxdb/
docker build -t grafana_alpine ./srcs/grafana/

# Install MetalLB
kubectl apply -f https://raw.githubusercontent.com/google/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/google/metallb/v0.9.3/manifests/metallb.yaml
kubectl apply -f ./srcs/metallb.yaml

#---------------------------------------------------

# Create pods and services
kubectl create -f ./srcs/nginx.yaml
kubectl apply -f srcs/mysql.yaml
kubectl create -f ./srcs/phpmyadmin.yaml
kubectl apply -f ./srcs/wordpress.yaml
kubectl create -f ./srcs/ftps.yaml
kubectl create -f ./srcs/influxdb.yaml
kubectl create -f ./srcs/grafana.yaml

runna=`kubectl get pod | grep mysql | grep Running`
while [[ $runna == '' ]]
do
    runna=`kubectl get pod | grep mysql | grep Running`
    sleep 4
done
mysqlpod=`kubectl get pods | grep mysql | tr ' ' '\n' | head -n 1`
kubectl exec $mysqlpod -- sh dump.sh

# Run dashboard
source ./dashboard/dashboard.sh