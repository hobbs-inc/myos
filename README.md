# MyOS

## Architecture
MyOS is structured around a microkernel architecture, designed to provide minimal functionality in the kernel while allowing user-space applications to handle everything else. The major components include:

- **Kernel**: The core component that manages CPU, memory, and processes.
- **User Space**: Where applications run, isolated from direct hardware access.
- **File System**: A robust file system providing access and file management capabilities.
- **Device Drivers**: Modules that allow the OS to communicate with hardware devices.

## Build Instructions
1. **Clone the repository**:
   ```
   git clone https://github.com/hobbs-inc/myos.git
   cd myos
   ```  
2. **Install Dependencies**:
   - Ensure you have the necessary development tools: `gcc`, `make`, etc.
3. **Build the Project**:
   ```
   make
   ```
4. **Run MyOS**:
   You can run MyOS in an emulator like QEMU:
   ```
   qemu-system-x86_64 -kernel myos.bin
   ```

## Roadmap
- **Q2 2026**: Complete user-space application interfaces.
- **Q3 2026**: Implement networking capabilities.
- **Q4 2026**: Optimize performance and reduce memory footprint.
- **2027**: Community contributions and feature enhancements.