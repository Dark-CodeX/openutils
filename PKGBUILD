pkgname="openutils-map"
pkgver="1.6.3"
pkgrel="3"
pkgdesc="Memory Safe Map Library in C/C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-map')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.hh" "https://raw.githubusercontent.com/Dark-CodeX/map/master/map/map.h" "https://raw.githubusercontent.com/Dark-CodeX/map/master/map/prototype_err.h")

sha512sums=("0657d9af749930005fd2e6ec886141c478d71ed0f405bcb3c06b8ca5698695134dfd4f5a3cf0ddcc77e267d9572458980b74cf7c72a2d2c3af3889ecb3fc5771" "772a9c904cb0efe343e1e47574d0819bae5bee97184798078d27556282b6b0533171a7e06238e463c35326d063cea1eee3207509d07701f6e2600a0af7d783f5" "7fdda2c66573cda0bd31d36326ee8c5ecebede37dac03eed0c43fc9d98ca1031511488e59ab0da6da7b59dff5510bcc8215824e456350cb0aaae20f8148d6bba")

package() {
  echo "Memory Safe Map Library in C++ language."
  mkdir -p "${pkgdir}/usr/include/openutils/map"
  cp "${srcdir}/map.hh" "${pkgdir}/usr/include/openutils/map/map.hh"
  cp "${srcdir}/map.h" "${pkgdir}/usr/include/openutils/map/map.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/map/prototype_err.h"
  echo "Done!"
}
