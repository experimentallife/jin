application=program
generator=

clean:
	rm -rf build/;

build:
	mkdir -p build; cd build; cmake ../.; make; cd ../.;

build-params:
	mkdir -p build; cd build; cmake -G $(generator) ../.; make; cd ../.;

run:
	cd build; ./$(application);

start:
	$(MAKE) clean; $(MAKE) build; $(MAKE) run;

application:
	echo Current application name is: $(application)