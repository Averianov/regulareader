#!/usr/bin/make

GOCMD=$(shell which go)
GOMOD=$(shell which go) mod
GOLINT=$(shell which golint)
GODOC=$(shell which doc)
GOBUILD=$(GOCMD) build
GOCLEAN=$(GOCMD) clean
GOTEST=$(GOCMD) test
GOGET=$(GOCMD) get
GOLIST=$(GOCMD) list
GOVET=$(GOCMD) vet
GORUN=$(GOCMD) run

compile:
	go mod tidy
	build.bat
	go build -o ./regulaclient.exe ./cmd

run: 
	make compile
	./regulaclient.exe
#	go run cmd/main.go
#	go run cmd/sharesms-launcher/main.go -debug-grpc=true

other:	
	#go get -u ./...
	#go env GOOS=windows GOARCH=amd64 CGO_ENABLED='1' CC=x86_64-w64-mingw32-gcc
	#go env GOOS=windows GOARCH=386 CC=i686-w64-mingw32-gcc
	#GOOS=windows GOARCH=386 CGO_ENABLED=1 CC=i686-w64-mingw32-gcc go build -buildmode=c-shared -o main.dll main.go
	#GOOS=windows GOARCH=amd64 CGO_ENABLED=1 CC=x86_64-w64-mingw32-gcc go build -buildmode=c-shared -o main.dll main.go

help:
	@echo 'Usage: make <OPTIONS> ... <TARGETS>'
	@echo ''
	@echo 'Available targets are:'
	@echo ''
	@echo '    compile                 	Build executable file.'
	@echo '    run                     	Start project without compile.'
	@echo '    help                    	Show this help screen.'
	@echo '    unit        			   	Run unit tests.'
	@echo '    test-integration        	Run integration tests.'
	@echo '    local-up                	Run service by docker compose'
	@echo '    local-down              	Stop service by docker compose'
	@echo '    local-restart           	Restart service by docker compose'
	@echo ''
	@echo 'Targets run by default are: fmt deps vet lint build test-unit.'
	@echo ''

unit:
	$(GOTEST) ./...

test-integration:
	$(GOTEST) ./test -v -count=1 -tags 'integration' -timeout 20m

local-up:
	./deployments/docker-compose up -d

local-down:
	./deployments/docker-compose down

local-restart: | local-down local-up


# dependency for fyne
# sudo apt install libgl-dev libglx-dev libxi-dev libxinerama-dev libxcb-xinerama0 libxrandr-dev libxcursor-dev libx11-dev libxxf86vm-dev

