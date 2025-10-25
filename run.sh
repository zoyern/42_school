#!/bin/bash
# Project Runner - Auto-setup dependencies and launch
set -e

PROJECT_NAME="42_school"  # Change this
PROJECT_DESC="Exercices et projets de 42"

### ===========================
### UI UTILITIES
### ===========================
BOLD='\033[1m'
CYAN='\033[36m'
GREEN='\033[32m'
YELLOW='\033[33m'
RED='\033[31m'
RESET='\033[0m'

print_header() {
    clear
    echo -e "${CYAN}╔════════════════════════════════════════════════════════════╗${RESET}"
    echo -e "${CYAN}║${RESET}  ${BOLD}$PROJECT_NAME${RESET}"
    echo -e "${CYAN}║${RESET}  ${PROJECT_DESC}"
    echo -e "${CYAN}╚════════════════════════════════════════════════════════════╝${RESET}\n"
}

show_status() {
    case $1 in
        "success") echo -e "  ${GREEN}✓${RESET} $2" ;;
        "error")   echo -e "  ${RED}✗${RESET} $2" ;;
        "info")    echo -e "  ${CYAN}ℹ${RESET} $2" ;;
        "warn")    echo -e "  ${YELLOW}⚠${RESET} $2" ;;
    esac
}

### ===========================
### DEPENDENCIES
### ===========================
install_dependencies() {
    echo -e "${BOLD}[1/3] Checking dependencies...${RESET}"
    
    # Liste des packages nécessaires (adapter selon projet)
    local PACKAGES=(
        # Exemples à décommenter selon besoin:
        # "python3"
        # "python3-pip"
        # "nodejs"
        # "npm"
        # "gcc"
        # "make"
        # "libreadline-dev"
    )
    
    # Si pas de packages, skip
    if [ ${#PACKAGES[@]} -eq 0 ]; then
        show_status "info" "No system dependencies required"
        return 0
    fi
    
    # Vérifier si déjà installé
    local MISSING=()
    for pkg in "${PACKAGES[@]}"; do
        if ! dpkg -l | grep -qw "$pkg"; then
            MISSING+=("$pkg")
        fi
    done
    
    if [ ${#MISSING[@]} -eq 0 ]; then
        show_status "success" "All dependencies installed"
        return 0
    fi
    
    # Installer les packages manquants
    show_status "info" "Installing: ${MISSING[*]}"
    sudo apt-get update -qq
    sudo apt-get install -y -qq "${MISSING[@]}"
    show_status "success" "Dependencies installed"
}

### ===========================
### BUILD
### ===========================
build_project() {
    echo -e "\n${BOLD}[2/3] Building project...${RESET}"
    
    # Choisir la méthode de build appropriée
    if [ -f "Makefile" ]; then
        show_status "info" "Building with Make..."
        make clean 2>/dev/null || true
        make
        show_status "success" "Build complete"
    elif [ -f "CMakeLists.txt" ]; then
        show_status "info" "Building with CMake..."
        mkdir -p build && cd build
        cmake .. && make
        cd ..
        show_status "success" "Build complete"
    elif [ -f "setup.py" ]; then
        show_status "info" "Installing Python dependencies..."
        pip3 install -e . --user
        show_status "success" "Setup complete"
    elif [ -f "package.json" ]; then
        show_status "info" "Installing Node dependencies..."
        npm install
        show_status "success" "Setup complete"
    else
        show_status "warn" "No build system detected"
    fi
}

### ===========================
### RUN
### ===========================
run_project() {
    echo -e "\n${BOLD}[3/3] Launching...${RESET}\n"
    
    # Adapter selon le type de projet
    if [ -f "main" ]; then
        ./main "$@"
    elif [ -f "build/main" ]; then
        ./build/main "$@"
    elif [ -f "main.py" ]; then
        python3 main.py "$@"
    elif [ -f "index.js" ]; then
        node index.js "$@"
    elif [ -f "Makefile" ]; then
        make run 2>/dev/null || show_status "warn" "No 'run' target in Makefile"
    else
        show_status "error" "No executable found"
        show_status "info" "Available files:"
        ls -lh
        return 1
    fi
}

### ===========================
### MAIN
### ===========================
main() {
    print_header
    install_dependencies
    build_project
    run_project "$@"
}

main "$@"
