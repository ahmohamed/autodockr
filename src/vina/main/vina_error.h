#ifndef VINA_ERROR_H
#define VINA_ERROR_H

struct vina_error {
	std::string error_message;
	vina_error(const std::string& error_message_ = "") : error_message(error_message_) {}
private:
	vina_error() {}
};

#endif
