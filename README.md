# 🤖 UnknowRobot STORM XI

_TO Satit Kaset ComTech Club Kids_

This robot I bought with school money, so now I have to give it back for you to use.

---

## 🧩 LOOKOUT FOR
- Added **voltage sensor code** (⚠️ not connected yet — you’ll need to solder and connect it yourself. Its in the box)
- Code for it is under **`UnknowRobotArudino.ino → voltage()`**

Use it like this:
```cpp
float j = voltage();
setk(0.895*20/21*1.0635*0.93*1.04*1.03);
```

Multiply j into setk() after connecting the voltage sensor (should work)
If you **don’t want to use the voltage sensor**, just multiply the constants manually.

---

## ⚙️ Setup & Calibration

To check if speed/voltage is calibrated:
1. Press **START** — it should turn **180°**.
2. If it’s not exactly 180°, tweak and multiply the constants in setk()


Write all your program code under:
```cpp
// CODE START HERE
Program1();
```

---

# 🛠 Other Stuff

- There should be **multiple gripper designs** lying around — try which works best for your needs.  
- There’s a **practice field (360cm × 240cm)** somewhere on campus.  
- **Superglue** is for fixing the wheel if it breaks too much.  
- **Cubes** are for testing the gripper.

---

# 🗒 Notes

My friend made some functions that _might or might not work_ (a lot don’t).  
Just use the **original ones** if in doubt.

**Original code folder:**  
[Google Drive link](https://drive.google.com/drive/folders/11dK5WG5Os6kRYebBeMF-xZqnZoDwQryf)
