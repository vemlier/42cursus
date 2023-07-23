all: 
	@sudo make setup 
	@make up

setup:
	@mkdir -p /home/chukim/data/wordpress
	@mkdir -p /home/chukim/data/mariadb
	@sudo echo "127.0.0.1 chukim.42.fr" >> /etc/hosts
	@echo "Directory created."

up:
	@docker compose -f ./srcs/docker-compose.yml up -d --build
	@echo "Containers started."

down:
	@docker compose -f ./srcs/docker-compose.yml down
	@echo "Containers stopped."

clean:
	@docker compose -f ./srcs/docker-compose.yml down --rmi all --volumes
	@echo "Containers stopped and images removed."

fclean: clean
	@sudo rm -rf /home/chukim/data
	@sudo sed -i '/chukim.42.fr/d' /etc/hosts
	@echo "Directory removed."

re:
	make fclean
	make all

.PHONY: all setup up down clean fclean re