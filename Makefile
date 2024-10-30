SRCS = main.c
LIBSRCS = open.c close.c put.c get.c random_level.c
TARG = kvs_static
TARG_DYNAMIC = kvs_dynamic

CC = gcc
OPTS = -Wall -g
LIBS = -L. -lkvs

OBJS = $(SRCS:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)
LARS = libkvs.a
LDLIBS = libkvs.so

all: static dynamic

static: $(TARG)

$(TARG) : $(OBJS) $(LARS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS) -static

$(LARS) : $(LOBJS)
	ar rs $(LARS) $(LOBJS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

dynamic: $(TARG_DYNAMIC)

$(TARG_DYNAMIC): $(OBJS) $(LDLIBS)
	$(CC) -o $(TARG_DYNAMIC) $(OBJS) $(LIBS)
$(LDLIBS): $(LOBJS)
	$(CC) -shared -o $(LDLIBS) $(LOBJS)

clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(TARG) $(TARG_DYNAMIC) $(LBLIBS)


