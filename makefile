object = downloader.o
compiler = gcc
flags = -lpthread -o	
target = grep
$(target) : $(object)
	$(compiler) $(flags) $(target) $(object)
	make refresh

main.o : grep.c

refresh :
	rm -f *.o
	rm -f /Output/*

clean :
	rm -f *.o
	rm -f $(target)
