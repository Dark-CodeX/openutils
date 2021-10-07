pkgname="sstring"
pkgver="17.0.10"
pkgrel="4"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h")
sha512sums=("618b15d774918236bbed2ec671bb6738769664d651c3da41278b9b0026a666486e88bb713f66cf2b635d8f3b450d740520928cb22d81d64d5ccb4664b0331dd9" "0be868c25172e6c7e19217517f586f827ae09c579c8b914f38ead4518c7a716e5b03d138e9940638c55f5cc173a5fc4739b16cae314ac2ecf553673ea0a346b0" "e86106e7a8190c5954f4c0c200a031b64d07d641811676646b56688b184bee0e46ad58688767109f35cd63656fb86b6b9f9f4719996db0fa2a92375edfc89c51")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  echo "Done!"
}
