SRCS_LIBFT_DIR	= ./libft/
SRCS_LIBFT_FILES= \
ft_pow.c ft_strlen.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isspace.c ft_isprint.c ft_tolower.c ft_min.c ft_max.c \
ft_toupper.c ft_strcmp.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memset.c ft_memcmp.c ft_memchr.c ft_memcpy.c \
ft_memmove.c ft_bzero.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_islower.c ft_isupper.c ft_strlcpy.c ft_strlcat.c \
ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS_LIBFT		= ${patsubst %, ${SRCS_LIBFT_DIR}%, ${SRCS_LIBFT_FILES}}

SRCS_GNL_DIR	= ./get_next_line/
SRCS_GNL_FILES	= get_next_line_bonus.c get_next_line_utils_bonus.c
SRCS_GNL		= ${patsubst %, ${SRCS_GNL_DIR}%, ${SRCS_GNL_FILES}}

SRCS_PRT_DIR	= ./ft_printf/
SRCS_PRT_FILES	= ft_printf.c ft_base_print.c ft_full_print.c ft_manage_params.c ft_printf_maths.c
SRCS_PRT		= ${patsubst %, ${SRCS_PRT_DIR}%, ${SRCS_PRT_FILES}}

HEADS			= -I.
OBJS			= ${SRCS_LIBFT:.c=.o} ${SRCS_GNL:.c=.o} ${SRCS_PRT:.c=.o}

NAME			= libft.a

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} ${HEADS}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
