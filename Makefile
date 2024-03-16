# Name of the executable
NAME			= push_swap

# Arguments passed to the executable
ARGS			= ${filter-out $@,${MAKECMDGOALS}}
PRINT_SCREEN	= YES

# Directories
SRCSDIR			= srcs/
OBJSDIR			= objs/
HDRDIR			= incl/
LIBFTDIR		= libft/

# Colors for the terminal
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m
ENDCOLOR		= \033[0m

# Background colors
BG_G			= \033[42m
BG_R			= \033[41m
BG_Y			= \033[43m
BG_B			= \033[44m
BG_M			= \033[45m
BG_C			= \033[46m
BG_W			= \033[47m

# Text formatting
BOLD			= \033[1m
UNDERLINE		= \033[4m
ITALIC			= \033[3m
INVERTED		= \033[7m

# Clear screen
CLEAR			= \033c

# Clear line
CLEARLN			= \r\033[K

# Sources
SRCS			= ${shell find ${SRCSDIR} -maxdepth 1 -type f -name '*.c'}
# OBJS			= ${patsubst ${SRCSDIR}%,${OBJSDIR}%,${SRCS:%.c=%.o}}
OBJS		=	$(SRCS:.c=.o)
LIBFT			= libft.a
CFLAGS			= -Wall -Wextra -Werror
CC				= cc
RM				= rm -rf
MKDIR			= mkdir -p

# Operating System
OS				:= ${shell uname}

# Progress bar messages
START			= echo "${YELLOW}\n🚀 Start of program compilation 🚀${ENDCOLOR}"
END_COMP		= echo "${GREEN}\n\n✅ Compilation completed successfully! ✅${ENDCOLOR}"
S_OBJS			= echo "${RED}🧹 Cleaning objects... 🧹${ENDCOLOR}"
S_NAME			= echo "${RED}🧹 Cleaning program... 🧹${ENDCOLOR}"
CHARG_LINE		= echo "${BG_G} ${ENDCOLOR}\c" && sleep 0.05
BS_N			= echo "\n"

# First rule
all: clear ${NAME}

# Build rule for object files
# ${OBJSDIR}/%.o : ${SRCSDIR}/%.c
# 	@${MKDIR} ${OBJSDIR}
# 	@${CC} ${CFLAGS} -I ${HDRDIR} -c $< -o $@

# Linking rule
${NAME}: ${OBJS}
	@echo "${CLEAR}\c"
	@${CHARG_LINE}
	@${MAKE} -C ${LIBFTDIR} > /dev/null 2>&1
	@${CHARG_LINE} ${C_LAST};
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBFTDIR}/${LIBFT}
	@${END_COMP}
	@sleep 0.5

#	This "> /dev/null 2>&1" redirects both outputs, and suppresses them this way

###############################################################################
#                   ↓↓↓↓↓           CLEANING           ↓↓↓↓↓                  #
###############################################################################

# Clean object files and executable
clean:
	@echo "${CLEAR}\c"
	@${S_OBJS}
	@${MAKE} clean -C ${LIBFTDIR} > /dev/null 2>&1
#	@${RM} objs/
	@${RM} ${OBJS}
	@sleep 0.3
	@echo "${CLEAR}\c"
	@echo "${GREEN}✅ Simple clean completed! ✨\n"

# Clean everything
fclean: clean
	@${S_NAME}
	@${MAKE} fclean -C ${LIBFTDIR} > /dev/null 2>&1
	@${RM} ${NAME}
	@sleep 0.3
	@echo "${CLEAR}\c"
	@echo "${GREEN}✅ Deep clean completed! ✨"

# Clear the screen
clear:
	@echo "${CLEAR}\c"

# Rebuild the program
re: fclean all

.PHONY: all clean fclean clear re