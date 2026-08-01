import re

with open("main.cpp", "r") as f:
    main_code = f.read()

main_code = main_code.replace("car->m_wheels[0].m_hasGroundContact = 1;", "for(int i=0; i<car->m_wheels.GetCount(); i++) { *(int*)((char*)&car->m_wheels[i] + 0x124) = 1; *(GmVec3*)((char*)&car->m_wheels[i] + 0xa8) = GmVec3(0,1,0); }")
main_code = main_code.replace("car->m_wheels[0].m_hasGroundContact = 0;", "for(int i=0; i<car->m_wheels.GetCount(); i++) { *(int*)((char*)&car->m_wheels[i] + 0x124) = 0; }")

with open("main.cpp", "w") as f:
    f.write(main_code)

print("Patched main")
