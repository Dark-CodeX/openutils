pkgname="sstring"
pkgver="34.0.0"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=("d51e45260b2f892b9c01c0d34cf569fffecc99079b4b8d212b5325a8636b1f3bbfbbbdfa97304c849c229c4e8695dde2a7df24d35c890d63b2e8b7e19f33578f" "6d147314b20a41856fe668bd1a463d39ed13ff829097f097d39bb779c6529fb4b0e2f94080b0ec9d5ad394d6d7d56d034e89d6bac9ba733c5d0a351a4d514ad1" "bf920e2da6511003cf918a7a12399a2d49c7ff7d8dfffcd4fd56816e6ded9c803ca6d012c1a19ea4d575becfdb807d4f6c0cbf74c6d146bdd371189584738353" "10dc52151087e222fba9b4018af1cdd9444ec5a9071a51fd950b3dd188828ecc936fd38024a2b052a68aff88b6fef2e3839843eb8b74f328ceb1fc9dfba7c4f8")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
