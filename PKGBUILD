pkgname="sstring"
pkgver="4.0.0"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("cdb14ab1c1bb54acd5e05bc490b5d9e3545f775424bcae42a7131f8f92a24212b3e52cf9f3f0ac68c604e1c0797e489989c0b58f9cbe614e9158cde6559972d4" "05be8513e013243fcce82f9bc39405830eb3805092fc1fea692615cb5408c8e9e9fc82c632e75ac374d37da4f7e153f8dc7971ce7b0decb6057ba1c3009fc601")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
