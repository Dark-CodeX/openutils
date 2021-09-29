pkgname="vector"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/prototype_err.h")
sha512sums=("1fae29ace878a8afc383becc2b81c339ade28ed131e217f2edac95cec221d52c04a8df62d3db224e84ff522861e94bc4ece9bdf64a4f8b666f9f9cfe39261f0b" "f8a28a6a9d3d62ac70552d2ec5a9e68fdd432527c27080a42ac2ffcd6416c681876801181b262e0bd19751124b4da4a92ab8dc183a43734b90db31e8cc20a904")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/vector/prototype_err.h"
  echo "Done!"
}