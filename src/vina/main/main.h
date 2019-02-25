#ifndef VINA_MAIN_H
#define VINA_MAIN_H
#include <string>
#include <boost/optional.hpp>

int vina_cpp(const vinaboost::optional<std::string>& rigid_name_opt,
	const vinaboost::optional<std::string>& flex_name_opt,
	std::string ligand_name,
	const vinaboost::optional<std::string>& out_name);

#endif
