/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:21:55 by marvin            #+#    #+#             */
/*   Updated: 2025/05/27 15:21:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::~MutantStack() {}
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}
template <typename T>
MutantStack<T>::MutantStack(MutantStack const &cpy) : std::stack<T>(cpy) {}

template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &cpy) { return (std::stack<T>::operator=(cpy), *this); }

template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::begin(){ return (this->c.begin()); }
template <typename T>
typename MutantStack<T>::iterator		MutantStack<T>::end(){ return (this->c.end()); }
template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin() const { return this->c.begin(); }
template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end() const { return this->c.end(); }
