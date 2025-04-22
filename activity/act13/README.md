```bash
docker build -t my-app .
docker tag my-app:latest localhost:50000/my-app:latest

docker run -d -p 5000:5000 --name local-registry registry:2

docker run --name registry -p 50000:5000 registry:2 
curl http://localhost:50000/v2/ 

docker push localhost:50000/my-app:latest


ip a
ipconfig getifaddr en0

docker pull 192.168.1.137:50000/my-app:latest

docker run -e secret_user=Idhibhat 192.168.1.137:50000/my-app:latest


```