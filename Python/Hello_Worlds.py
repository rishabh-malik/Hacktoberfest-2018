import time

hello_world = ["こんにちは世界", "salve Orbis Terrarum", "Hello World", "Hello Wêreld", "Përshendetje Botë", "مرحبا بالعالم", "你好，世界", "Ahoj světe",
                 "Bonjour le monde", "Hallo Welt", "Ciao mondo", "Witaj świecie", "Привет мир", "Hallo Wereld"]
# Hello World in different languages

while True:
# Forever loop
    for hello in hello_world:
    # for "hello" (A random var name) in the list called "hello_world":
        print(hello)
        # print the previously created "hello" var, this var gets changed for every entry in the list! So this repeats till all of the entries have been in this loop.
        time.sleep(1)
        # add delay so it says hello every second
