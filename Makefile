# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 14:36:04 by dcastor           #+#    #+#              #
#    Updated: 2025/05/11 16:42:52 by dcastor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================== #
#                                 CONFIGURATION                                  #
# ============================================================================== #

# 📛 Nom du programme
NAME := push_swap
LIB_NAME := libft

# 📂 Répertoires
SRCS_DIR := srcs/
BUILD_DIR := build/
LIB_DIR := $(LIB_NAME)/
INCLUDE_DIRS := -I$(LIB_DIR)/includes -Iincludes

# 📦 Compiler & Flags
CC := cc
CFLAGS := -Wall -Wextra -Werror -g -MMD $(INCLUDE_DIRS)

# 🛠 Utilitaires
MAKE := make

# 📁 Sources & Objets
SRCS := $(addprefix $(SRCS_DIR), \
		main.c \
		init.c \
		utils/error.c \
		utils/normalize.c \
		sort/radix_sort.c \
		stack/push.c \
		stack/swap.c \
		stack/rotate.c \
		stack/reverse_rotate.c \
)
OBJS := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

# 📚 Libft
LIB_FILE := $(LIB_NAME).a

# ============================================================================== #
#                               RULES - BUILD FLOW                               #
# ============================================================================== #

# 🎯 Règle principale
all: $(NAME)

# 🧱 Construction de l'exécutable
$(NAME): $(BUILD_DIR) $(BUILD_DIR)$(LIB_FILE) $(OBJS)
	@echo "[$(NAME)] 🚧 Linking executable..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(BUILD_DIR) -lft
	@#$(CC) $(CFLAGS) -o $(BUILD_DIR)$(NAME) $(OBJS) -L$(BUILD_DIR) -lft
	@#ln -s $(BUILD_DIR)$(NAME) $(NAME)

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
$(BUILD_DIR)$(LIB_FILE): $(BUILD_DIR) $(LIB_DIR)
	@$(MAKE) -C $(LIB_DIR) && mv $(LIB_DIR)$(LIB_FILE) $(BUILD_DIR)$(LIB_FILE)

# 📥 Clone la libft si absente
$(LIB_DIR):
	@if [ ! -d $(LIB_DIR) ]; then \
		echo "🔁 Cloning libft repository..."; \
		git clone git@github.com:DylanC-Code/Libft.git $(LIB_DIR); \
	fi

# ============================================================================== #
#                                   CLEAN RULES                                  #
# ============================================================================== #

clean:
	@echo "🧼 Cleaning build files..."
	@rm -fr $(BUILD_DIR)
	@echo "✅ Clean complete"

fclean: clean
	@echo "🧨 Removing executable..."
	@rm -f $(NAME)
	@echo "✅ Executable removed"

re: fclean all

# ============================================================================== #
#                                    TEST RULES                                  #
# ============================================================================== #


# ============================================================================== #
#                                  PHONY & DEPS                                  #
# ============================================================================== #

# 📌 Cibles qui ne sont pas des fichiers
.PHONY: all clean fclean re

# 📎 Inclusion des dépendances générées automatiquement
-include $(DEPS)
