import re

with open("main.cpp", "r") as f:
    orig = f.read()

orig = orig.replace("uint32_t currentEventIdx = 0;", """
    for(int i = std::max(0, (int)replay->m_events.size() - 10); i < replay->m_events.size(); i++) {
        std::cout << "LastEv[" << i << "] t=" << replay->m_events[i].time << " ctrl=" << (int)replay->m_events[i].controlIdx << " val=" << replay->m_events[i].value << std::endl;
    }
    uint32_t currentEventIdx = 0;
""")

with open("main.cpp", "w") as f:
    f.write(orig)
