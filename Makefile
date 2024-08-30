# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samunyan <samunyan@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 18:04:51 by samunyan          #+#    #+#              #
#    Updated: 2022/09/29 18:04:52 by samunyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP 	=	push_swap_files

CHECKER		=	checker_files

all:
	@make -C $(PUSH_SWAP) && cp $(PUSH_SWAP)/push_swap .

bonus:
	@make -C $(CHECKER) && cp $(CHECKER)/checker .

clean:
	@make -C $(PUSH_SWAP) clean
	@make -C $(CHECKER) clean

fclean:
	@make -C $(PUSH_SWAP) fclean
	@make -C $(CHECKER) fclean

re:
	@make -C $(PUSH_SWAP) re

bonus_re:
	@make -C $(CHECKER) re

sanitizer:
	@make -C $(PUSH_SWAP) sanitizer && cp $(PUSH_SWAP)/push_swap .

debug:
	@make -C $(PUSH_SWAP) debug && cp $(PUSH_SWAP)/push_swap .

bonus_sanitizer:
	@make -C $(CHECKER) sanitizer && cp $(CHECKER)/checker .

bonus_debug:
	@make -C $(CHECKER) debug && cp $(CHECKER)/checker .