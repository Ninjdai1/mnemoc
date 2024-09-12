# MnemoC

## Dependencies

Install gtkmm 4.0
<details>
    <summary>Debian/Ubuntu</summary>

    ```bash
    # apt install libgtkmm-4.0-dev
    ```
</details>
<details>
    <summary>RedHat/Fedora</summary>

    ```bash
    # dnf install gtkmm4.0-devel
    ```
</details>
<details>
    <summary>ArchLinux and derivatives</summary>

    ```bash
    # pacman -S gtkmm-4.0
    ```
</details>

## Build instructions

First, set make up:
```sh
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
```

Then, to compile the project:
```sh
cmake --build . -- -j"$(nproc)"
```
