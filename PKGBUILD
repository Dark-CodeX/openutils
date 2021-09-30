pkgname="vector"
pkgver="4.0.0"
pkgrel="1"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/prototype_err.h")
sha512sums=("21be7f081a271ac53e489ac635fbe8d963ea6e839b625696878545810602a27252c206174013aeb7de5bc6ae21a80e2544bff1cc5e01ea5bb4f20bfba91e793b" "57e6b59fe46ebb66eb61729e2b7324d11ab08d51299634f39414da9da36b75c81458d5c67fe05248b989d5daa36b598a82bb39b3fb8b642a66f516536e7653f7")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/vector/prototype_err.h"
  echo "Done!"
}