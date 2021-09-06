pkgname="sstring"
pkgver="4.1.5"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("b8256eaf9dbbc3825a5f417c12c405382baedb46590c98ef6ff89d5a16272b8ccc7137dfb5ffa7a31082b6a7d06e8a9204e32490d58f1563e652856d5e475728" "94f48662bb471414b1040b2473020dd993c93c6aca8087f9e0ad3db1e0e51bf803b3a87d0f49f54650b46e6a8627056e3d214a21829c0cd3adfbd9f129a62f58")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
