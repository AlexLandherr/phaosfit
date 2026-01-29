# ---- Config ----
APP     = phaosfit
CC      = gcc
CFLAGS  = -std=c17 -Wall -Werror -g
LDFLAGS =
OBJDIR  = obj
SRCDIR  = src

# ---- Derive lists ----
# Find all .c files anywhere under src/
SRCS = $(shell find $(SRCDIR) -type f -name '*.c')

# Map src/foo/bar.c -> obj/foo/bar.o
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

# ---- Default ----
all: $(APP)

$(APP): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

# Compile C -> obj (emit .d dep files). Create target dir on the fly.
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# include deps if present
-include $(DEPS)

# ---- Housekeeping ----
.PHONY: clean
clean:
	@rm -rf $(OBJDIR) $(APP)
	@find . -name '*.d' -delete
