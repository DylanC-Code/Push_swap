# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 14:36:04 by dcastor           #+#    #+#              #
#    Updated: 2025/05/19 15:13:49 by dcastor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================== #
#                                 CONFIGURATION                                  #
# ============================================================================== #

# 📛 Nom du programme
NAME := push_swap
LIB_NAME := Libft

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
		parser.c \
		commands/rotate.c \
		commands/reverse_rotate.c \
		commands/push.c \
		sort/sort.c \
		sort/cheapest.c \
		sort/find_indexes.c \
		sort/find_lis.c \
		sort/find_pivot.c \
		sort/perform_cheapest_move.c \
		sort/push_to_b.c \
		stack/dlist_utils.c \
		stack/stack_utils.c \
)
OBJS := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

# 📚 Libft
LIB_FILE := libft.a

# ============================================================================== #
#                               RULES - BUILD FLOW                               #
# ============================================================================== #

# 🎯 Règle principale
all: $(NAME)

# 🧱 Construction de l'exécutable
$(NAME): $(BUILD_DIR) $(LIB_DIR)$(LIB_FILE) $(OBJS)
	@echo "[$(NAME)] 🚧 Linking executable..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_DIR) -lft

# 🔨 Compilation des .c vers .o
$(BUILD_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[$(NAME)] 🧩 Compiling $<"

# ============================================================================== #
#                            DIRECTORY & LIBRARY SETUP                           #
# ============================================================================== #

# 📁 Création du dossier de build
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@echo "📁 Build directory created"

# 📚 Build libft.a
$(LIB_DIR)$(LIB_FILE): $(LIB_DIR)
	@$(MAKE) -C $(LIB_DIR)

# ============================================================================== #
#                                   CLEAN RULES                                  #
# ============================================================================== #

clean:
	@echo "🧼 Cleaning build files..."
	@rm -fr $(BUILD_DIR) && make -C $(LIB_DIR) clean
	@echo "✅ Clean complete"

fclean: clean
	@echo "🧨 Removing executable..."
	@rm -f $(NAME) && make -C $(LIB_DIR) fclean
	@echo "✅ Executable removed"

re: fclean all

# ============================================================================== #
#                                    TEST RULES                                  #
# ============================================================================== #

test:
	@if [ ! -d "push_swap_tester" ]; then \
		echo "🔁 Cloning push_swap_tester repository..."; \
		git clone git@github.com:SimonCROS/push_swap_tester.git push_swap_tester; \
		make fr -C push_swap_tester && mv push_swap_tester/complexity tester; \
	fi
	@echo "🧪 Running tests..."
	@./tester 100 1 700 ./checker_linux -o tamere

# ============================================================================== #
#                                  PHONY & DEPS                                  #
# ============================================================================== #

# 📌 Cibles qui ne sont pas des fichiers
.PHONY: all clean fclean re

# 📎 Inclusion des dépendances générées automatiquement
-include $(DEPS)
