kubectl delete --all deployments
kubectl delete --all pods
kubectl delete --all services
kubectl delete --all pvc

kubectl delete -f srcs/
kubectl delete -f srcs/volume/

#stop all container
docker stop $(docker ps -aq)

#remove all container
docker rm -f $(docker ps -aq)

#remove all images
docker rmi -f $(docker images -q)