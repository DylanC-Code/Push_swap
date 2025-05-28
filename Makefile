# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 14:36:04 by dcastor           #+#    #+#              #
#    Updated: 2025/05/28 10:08:07 by dcastor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================== #
#                                 CONFIGURATION                                  #
# ============================================================================== #

# 📛 Nom du programme
NAME := push_swap
BONUS_NAME := checker
LIB_NAME := libft

# 📂 Répertoires
SRCS_DIR := srcs/
BUILD_DIR := build/
LIB_DIR := $(LIB_NAME)/
INCLUDE_DIRS := -I$(LIB_DIR)includes -Iincludes

# 📦 Compiler & Flags
CC := cc
CFLAGS := -Wall -Wextra -Werror -g -MMD $(INCLUDE_DIRS)

# 🛠 Utilitaires
MAKE := make

# 📁 Sources & Objets
SRCS := $(addprefix $(SRCS_DIR), \
		main.c \
		calcul_best_elem.c \
		check_arguments.c \
		check_error.c \
		largest_increasing_sub.c \
		moves1.c \
		moves2.c \
		push_a_to_b.c \
		push_b_to_a.c \
		push_swap_utils.c \
		push_swap_utils2.c \
		savage.c \
		sort_five.c \
		sort_three.c \
		stack_utils.c \
)
OBJS := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))
SRCS_BONUS = $(addprefix $(SRCS_DIR), \
	checker_bonus.c \
	checker_utils_bonus.c  \
	sort_three.c \
	push_a_to_b.c \
	calcul_best_elem.c \
	push_b_to_a.c \
	check_arguments.c \
	check_error.c \
	largest_increasing_sub.c \
	push_swap_utils.c \
	push_swap_utils2.c \
	moves1.c \
	moves2.c \
	savage.c \
	sort_five.c \
	stack_utils.c \
)
OBJS_BONUS := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS_BONUS))

DEPS := $(OBJS:.o=.d)
DEPS_BONUS := $(OBJS_BONUS:.o=.d)

# 📚 Libft
LIB_FILE := libft.a

# ============================================================================== #
#                               RULES - BUILD FLOW                               #
# ============================================================================== #

# 🎯 Règle principale
all: $(NAME)

# 🧱 Construction de l'exécutable
$(NAME): $(BUILD_DIR) $(LIB_DIR)$(LIB_FILE) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_DIR) -lft

bonus: $(BUILD_DIR) $(LIB_DIR)$(LIB_FILE) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) -L$(LIB_DIR) -lft

# 🔨 Compilation des .c vers .o
$(BUILD_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


# ============================================================================== #
#                            DIRECTORY & LIBRARY SETUP                           #
# ============================================================================== #

# 📁 Création du dossier de build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 📚 Build libft.a
$(LIB_DIR)$(LIB_FILE): $(LIB_DIR)
	$(MAKE) -sC $(LIB_DIR)

# ============================================================================== #
#                                   CLEAN RULES                                  #
# ============================================================================== #

clean:
	rm -fr $(BUILD_DIR) && make -sC $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) && make -sC $(LIB_DIR) fclean

re: fclean all

# ============================================================================== #
#                                    TEST RULES                                  #
# ============================================================================== #

test: $(NAME) $(BONUS_NAME)
	@if [ ! -d "push_swap_tester" ]; then \
		echo "🔁 Cloning push_swap_tester repository..."; \
		git clone git@github.com:SimonCROS/push_swap_tester.git push_swap_tester; \
		make fr -C push_swap_tester && mv push_swap_tester/complexity tester; \
	fi
	@echo "🧪 Running tests..."
	./tester 100 100 700 ./checker
	./tester 500 100 5500 ./checker

test_leak: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --log-fd=1 ./push_swap

# ============================================================================== #
#                                  PHONY & DEPS                                  #
# ============================================================================== #

# 📌 Cibles qui ne sont pas des fichiers
.PHONY: all clean fclean re

# 📎 Inclusion des dépendances générées automatiquement
-include $(DEPS) $(DEPS_BONUS)
