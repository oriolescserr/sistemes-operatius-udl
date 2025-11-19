all: ohmy_sudo

ohmy_sudo: ohmy_sudo.o 
	gcc $< -o $@

ohmy_sudo.o: ohmy_sudo.c
	gcc -c $< -o $@

configure:
	@echo "Configurant permisos per a ohmy_sudo..."

	# Canviem el propietari del fitxer a root (usuari i grup)
	# Això fa que el binari pertanyi a root, necessari per al setuid
	chown root:root ./ohmy_sudo

	# Activem el bit setuid (u+s), que permet que el programa s’executi
	# amb els privilegis del seu propietari (root) encara que el llanci un usuari normal
	chmod u+s ./ohmy_sudo

	@echo "Permisos configurats correctament."

test:
	sudo useradd -m test || true
	sudo -u test ./ohmy_sudo whoami || true
	make configure
	sudo -u test ./ohmy_sudo whoami || true
	sudo userdel -r test || true

run:
	./ohmy_sudo $(ARGS)

clean:
	rm -f ohmy_sudo.o ohmy_sudo
