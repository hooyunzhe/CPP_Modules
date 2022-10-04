#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(string target) : AForm("ShrubberyCreationForm", target, 145, 137) {
	cout << GREEN "ShrubberyCreationForm constructor called\n" RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf_var) : AForm(scf_var.getName(), scf_var.getTarget(), scf_var.getSignGrade(), scf_var.getExecuteGrade()) {
	cout << BLUE "ShrubberyCreationForm copy constructor called\n" RESET;
	this->signForm(scf_var.isSigned());
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	cout << RED "ShrubberyCreationForm destrutor called\n" RESET;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator = (const ShrubberyCreationForm &scf_var) {
	cout << CYAN "ShrubberyCreationForm copy assignment operator called\n" RESET;
	this->signForm(scf_var.isSigned());
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	this->checkExecutable(executor);
	ofstream	shrubFile(this->getTarget() + "_shrubbery");

	shrubFile << "              _{\\ _{\\{\\/}/}/}__\n";
	shrubFile << "             {/{/\\}{/{/\\}(\\}{/\\} _\n";
	shrubFile << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n";
	shrubFile << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n";
	shrubFile << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n";
	shrubFile << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n";
	shrubFile << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n";
	shrubFile << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n";
	shrubFile << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n";
	shrubFile << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n";
	shrubFile << "      {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n";
	shrubFile << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n";
	shrubFile << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n";
	shrubFile << "        {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n";
	shrubFile << "         (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n";
	shrubFile << "           {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n";
	shrubFile << "             {/{\\{\\{\\/}/}{\\{\\}/}\n";
	shrubFile << "              {){/ {\\/}{\\/} \\}\\}\n";
	shrubFile << "              (_)  \\.-'.-/\n";
	shrubFile << "          __...--- |'-.-'| --...__\n";
	shrubFile << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n";
	shrubFile << " -\"    ' .  . '    |.'-._| '  . .  '   jro\n";
	shrubFile << " .  '-  '    .--'  | '-.'|    .  '  . '\n";
	shrubFile << "          ' ..     |'-_.-|\n";
	shrubFile << "  .  '  .       _.-|-._ -|-._  .  '  .\n";
	shrubFile << "              .'   |'- .-|   '.\n";
	shrubFile << "  ..-'   ' .  '.   `-._.-�   .'  '  - .\n";
	shrubFile << "   .-' '        '-._______.-'     '  .\n";
	shrubFile << "         .      ~,\n";
	shrubFile << "     .       .   |\\   .    ' '-.\n";
	shrubFile << "     ___________/  \\____________\n";
	shrubFile << "    /  Why is it, when you want \\\n";
	shrubFile << "   |  something, it is so damn   |\n";
	shrubFile << "   |    much work to get it?     |\n";
	shrubFile << "    \\___________________________/\n";
	shrubFile.close();
}