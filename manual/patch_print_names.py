import re

with open("main.cpp", "r") as f:
    orig = f.read()

orig = orig.replace("First Event Time:", """
    std::cout << "Control Names:" << std::endl;
    for(int i = 0; i < replay->m_controlNames.size(); i++) {
        std::cout << i << ": " << replay->m_controlNames[i] << std::endl;
    }
    std::cout << "First Event Time:";
""")

with open("main.cpp", "w") as f:
    f.write(orig)
