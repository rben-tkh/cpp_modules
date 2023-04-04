/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:18:14 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/30 18:18:14 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string type){setType(type);}

Weapon::Weapon(void){}

Weapon::~Weapon(void){}

const std::string	&Weapon::getType(void)const{return(type);}

void	Weapon::setType(std::string new_type){type = new_type;}
