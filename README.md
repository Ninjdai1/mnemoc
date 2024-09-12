# MnemoC

## Dependencies

Install gtkmm 4.0
<details>
    <summary>Debian/Ubuntu</summary>

    Using aptitude
    ```bash
    # apt install libgtkmm-4.0-dev
    ```
</details>
<details>
    <summary>RedHat/Fedora</summary>

    Using DNF
    ```bash
    # dnf install gtkmm4.0-devel
    ```
</details>
<details>
    <summary>ArchLinux and derivatives</summary>

    Using pacman
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
