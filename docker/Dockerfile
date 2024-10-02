FROM ubuntu:latest
LABEL authors="jmfrouin"

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    g++ \
    && rm -rf /var/lib/apt/lists/*

# Définir le répertoire de travail
WORKDIR /app

# Copier le code source dans le conteneur
COPY . .

# Construire l'application
RUN cmake . && make

# Commande par défaut pour exécuter l'application
CMD ["./eOS"]